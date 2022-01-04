//
//  DictionarySearchTree.h
//  scs202hw3
//
//  Created by Zeynep Büsra Ziyagil on 19.07.2021.
//

#ifndef DictionarySearchTree_h
#define DictionarySearchTree_h
#include <string>
using namespace  std;

//Search tree implementation for the dictionary
class DictionarySearchTree {
public:
//Constructor that constructs the dictionary from the input file
DictionarySearchTree( string dictionaryFile );
//Destructor
virtual ~DictionarySearchTree();
//Inserts the given word into the dictionary
virtual void insert( string word );
//Searches the given word in the dictionary, and returns the number
//of comparisons made and whether the word is found or not
virtual void search( string word, int& numComparisons, bool& found ) const;
//Searches all words in the query file in the dictionary, and
//summarizes the results in the output file
virtual void search( string queryFile, string outputFile ) const;
 
};
#endif /* DictionarySearchTree_h */
