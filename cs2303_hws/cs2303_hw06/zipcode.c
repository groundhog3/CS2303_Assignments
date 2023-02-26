/** Program demonstrating parsing and linked lists. This program 
 * supports zip code lookup for any town in Massachusetts
 *
 * @author Blake Nelson, Ryan Mechery
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <forward_list>
#include <readline/readline.h>
#include <readline/history.h>
#include <iostream>
#include "zipfed.hpp"
//#include "zipfilter.h" - not sure what this is

// size of fully qualified path/file name with null terminator
#define SZ_FILENAME (129)

//max size of input line buffer
#define MAXLINE (4096)


/** Function to read a line from the fed2cs2303 zip and return pointer to the 
 * line of data represented as a C-String (i.e. NULL terminated string)
 *
 * @lineptr is a pointer to the dynamically allocated buffer to fill.
 *   If the pointer is NULL, a buffer will be allocated to hold the line.
 *   If the buffer is too small to hold the line, realloc will be called
 *   to allocate a larger buffer. If the buffer is reallocated, n will
 *   be set to new size.
 * @n is a pointer to the size of the buffer pointer to be lineptr. If
 *   memory is reallocated for lineptr, the size of n will be incremented
 *   accordingly. The parameter n will always specify the size of buffer
 *   pointed at by lineptr.
 * @fptr is the FILE pointer to the open file to read.
 * @return number bytes (chars) read or -1 on error
 */
ssize_t readln_fedcs2303(char **lineptr, size_t *n, FILE *stream) {
  ssize_t bytes_read = -1;  // -1 will signify error reading line
  const int delim = '\n';   // each line terminated with \n

  // Verify the file is open
  if (stream == NULL) {
    return (ssize_t) -1;
  }

  // Each line of the FED ZIP CSV file is terminated by \n, so we
  // read up to and including the \n for the entire line
  bytes_read = getdelim (lineptr, n, delim, stream);

  // Remove the \n at the end of the line by replacing with NULL terminator
  // Expect length of at least 2 for the \n at end of a line
  for (int i = bytes_read - 1; i >= 0; i--) {
    if ((*lineptr)[i] == '\n') {
      (*lineptr)[i] = '\0';
    }
  }
    
  return bytes_read;
}

/** Custom comparator for forward list based on zipfed city attr.
 *  @param pZip1 pointer to first zipfed object
 *  @param pZip2  pointer to second zipfed object 
 *  @return true if pZip1.city lex. less than pZip2.city
 *  @return false
 * */
bool comparator_function(Zipfed* pZip1, Zipfed* pZip2) { 
 // return true if pZip1's city is less than pZip2's city, else return false 
    return pZip1->get_city().compare(pZip2->get_city()) < 0;
} 

/** program to find the zip code for any town in Massachusetts
 *
 * @param argc is the number of field on command line - should be 1
 * @param argv is array of strings entered on command line - prog name
 * @return 0 for success
 * @return 1 for failure
 */
int main (int argc, char *argv[]) {
    char infile[SZ_FILENAME];  // Path/name of input file
    FILE *fdIn;
    
    ssize_t chars_read;        // number of chars read for line of input
    char *inbuf = NULL;        // input file has 1 record per line to buffer
    size_t sz_inbuf = 0;       // current size of the input record

    std::forward_list<Zipfed *> llist; // singly linked list of pointers to Zipfed instances

    /* Open input and output files specified on command line
    * Common sense error checking on cmd line parameters
    */
    if (argc != 2) {
        fprintf(stderr, "usage: %s input_file\n", argv[0]);
        return -1;
    }

    strncpy(infile, argv[1], SZ_FILENAME-1);

    /* Open input and output files - return error on failure
    * input for reading. output for writing
    */
    fdIn = fopen(infile, "r");
    if (fdIn == NULL) {
        fprintf(stderr, "cannot open %s for input - exiting\n", infile);
        return -2;
    }

    // Now loop to process each line of zip code data in CSV format
    while ((chars_read = readln_fedcs2303(&inbuf, &sz_inbuf, fdIn)) != EOF) {
        if (chars_read == 0) {  // not EOF, but nothing to process
          continue;
        }

        // write the buffer to stdout for debugging
        #ifdef DEBUG
            printf("inbuf: %s\n", inbuf);
        #endif
        
        // for each input line we create a new object instance of Zipfed, have the object
        // parse the input record and initialize itself with the parse result
        // Nonzero return indicates error parsing
        Zipfed *pZipfed = new Zipfed();
        if(pZipfed->parse_zip_cs2303(inbuf) != 0) {
          fprintf (stderr, "failed to process input record - exiting\n");
          fclose (fdIn);
          return -4;
        }
        
        // write the structure to stdout to verify processing during development
        /* printf ("DEBUG: "); */
        /* pZipfed->print(); */

        // Add the city to linked list if any string 
        // from queries vector matches object
        llist.push_front(pZipfed);
    }

    //sort list by city name alphabetically
    llist.sort(comparator_function);

    printf("All items from %s were processed successfully!\n\n", infile);

    char * buffer = (char *) calloc(1, MAXLINE); 
    //dyn. allocated space for line buffer

    printf("Enter city names line by line: (CTRL+D to stop)\n");

    size_t buff_idx; //counter for loop
    // this loop terminates when readline is null
    for(buff_idx = 0; (buffer = readline("_ ")) != NULL ; buff_idx++){
        // Now iterate through the list to make sure it's all there
        // zipprint will print the struct to output stream
        for(std::forward_list<Zipfed *>::iterator it = llist.begin(); it != llist.end(); it++) {
            Zipfed * pTmpZipfed = *it;
            //only print city if from city
            if(pTmpZipfed->is_from(buffer))
                std::cout << pTmpZipfed->get_zip() << "\n";
        }
    }
    printf("\n");
    

    /* Free memory before exiting
   * keep deleting the head until list is empty.
   * this code is responsible for freeing the zip code data struct
   * the linked list will free the node form the linked list
   */
    while (!llist.empty()) {
        llist.pop_front();
    }

    free(buffer);

    return 0;
}

