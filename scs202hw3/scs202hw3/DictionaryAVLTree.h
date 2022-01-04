//
//  DictionaryAVLTree.h
//  scs202hw3
//
//  Created by Zeynep Büsra Ziyagil on 19.07.2021.
//

#ifndef DictionaryAVLTree_h
#define DictionaryAVLTree_h
#include <string>
#include "DictionarySearchTree.h"
#include "BinaryNode.h"

#include <sstream>
#include <fstream>
using namespace std;

class DictionaryAVLTree: public DictionarySearchTree{
public:
    DictionaryAVLTree( string dictionaryFile): DictionarySearchTree( dictionaryFile){
        
        this->root =NULL;
        ifstream infile;
        infile.open(dictionaryFile.c_str());

        
        string theline;
       
        if (infile.is_open()) {
            while (getline(infile, theline)) {
            string str =theline.c_str();
                insert(str);
            }
            
            infile.close();
         
        }
    }
    void insert( string word );
    //Searches the given word in the dictionary, and returns the number
    //of comparisons made and whether the word is found or not
    void search( string word, int& numComparisons, bool&   found ) const;
    //Searches all words in the query file in the dictionary, and
    //summarizes the results in the output file
    void search( string queryFile, string outputFile )  const;
    BinaryNode* root; 
    void  containsit(BinaryNode *rootNode,string word, bool &boolr,int &compcount)const;
   
    BinaryNode* insertrotate(BinaryNode *node, const string &word) ;

    // height of AVL tree
    int getHeight(BinaryNode *node) ;
    int getBalance(BinaryNode *node);


    BinaryNode* rotateright(BinaryNode *node);
  
    BinaryNode* rotateleft(BinaryNode *node);
};

#endif /* DictionaryAVLTree_h */
