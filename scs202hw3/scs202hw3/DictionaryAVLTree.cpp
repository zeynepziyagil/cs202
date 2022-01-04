//
//  DictionaryAVLTree.cpp
//  scs202hw3
//
//  Created by Zeynep Büsra Ziyagil on 19.07.2021.
//
#include <stdio.h>
#include <string>
#include "DictionaryAVLTree.h"
#include <iostream>
#include <sstream>
#include <fstream>
int DictionaryAVLTree::getHeight(BinaryNode *binode) {
    if (binode == NULL)
        return 0;
    
    int left = getHeight(binode->leftChildPtr);
    int right = getHeight(binode->rightChildPtr);
    
    return 1 + max(left, right);
}

void DictionaryAVLTree::insert(string word) {
    root = insertrotate(root, word);
    //UPDATE ROOT
}

BinaryNode* DictionaryAVLTree::insertrotate(BinaryNode *binode, const string &word) {
 
    if (!binode) {
        binode = new BinaryNode(word, NULL, NULL);
        return(binode);
    }
    
    if (word < binode->item)
    {binode->leftChildPtr  = insertrotate(binode->leftChildPtr, word);}
    else if (word > binode->item)
    { binode->rightChildPtr = insertrotate(binode->rightChildPtr, word);}
    else
    {return binode;}
    
    binode->height = 1 + max(getHeight (binode->leftChildPtr), getHeight(binode->rightChildPtr));
    
    int balance = getBalance(binode);
    // LL
    if (balance > 1 && word < binode->leftChildPtr->item)
        return rotateright(binode);
    
    // RR
    if (balance < -1 && word > binode->rightChildPtr->item)
        return rotateleft(binode);
    
    // LR
    if (balance > 1 && word > binode->leftChildPtr->item) {
        binode->leftChildPtr =  rotateleft(binode->leftChildPtr);
        return rotateright(binode);
    }
    
    // RL
    if (balance < -1 && word < binode->rightChildPtr->item) {
        binode->rightChildPtr= rotateright(binode->rightChildPtr);
        return rotateleft(binode);
    }
    return binode;
}





// Case 1: Right Rotation
BinaryNode* DictionaryAVLTree::rotateright(BinaryNode *binode) {
    BinaryNode *turntr = binode->leftChildPtr;
    BinaryNode *take = turntr->rightChildPtr;
    
    // Perform rotation
    turntr->rightChildPtr = binode;
    binode->leftChildPtr = take;
    
    // Update heights
    binode->height = max(getHeight(binode->leftChildPtr), getHeight(binode->rightChildPtr)) + 1;
    turntr->height = max(getHeight(turntr->leftChildPtr), getHeight(turntr->rightChildPtr)) + 1;
    
 
    return turntr;
}


BinaryNode* DictionaryAVLTree::rotateleft(BinaryNode *binode) {
    BinaryNode *turnt = binode->rightChildPtr;
    BinaryNode *take = turnt->leftChildPtr;
    turnt->leftChildPtr = binode;
    binode->rightChildPtr = take;
    binode->height = max(getHeight(binode->leftChildPtr), getHeight(binode->rightChildPtr)) + 1;
    turnt->height = max(getHeight(turnt->leftChildPtr), getHeight(turnt->rightChildPtr)) + 1;
    return turnt;
}

int DictionaryAVLTree::getBalance(BinaryNode *binode) {
    if (!binode)
        return 0;
    return getHeight(binode->leftChildPtr) - getHeight(binode->rightChildPtr);}
                        



void DictionaryAVLTree::search( string word, int& numComparisons, bool& found ) const{
   
    containsit(root ,word, found, numComparisons);

    
}
//Searches all words in the query file in the dictionary, and
//summarizes the results in the output file
void DictionaryAVLTree::search( string queryFile, string outputFile )  const{
    
    ifstream infile;
    infile.open(queryFile.c_str());
    ofstream outfile;
    outfile.open(outputFile.c_str());
    
    string theline;
    int compcount =0;
    bool foundbool = false;
    int querynum = 0;
    int * comparisons = new int [1];
    
    if (infile.is_open()) {
        while (getline(infile, theline)) {
        querynum++;
        compcount =0;
        foundbool = false;
        string str =theline.c_str();
            search(str, compcount, foundbool);
            int * temp = new int[querynum];
            for(int i = 0; i<querynum;i++){
                temp[i] = comparisons[i];
                
            }
            temp[querynum-1]= compcount;
            delete[] comparisons;
            comparisons = temp;
            outfile<<setw(15)<<str<<"  "<<foundbool<<"  "<<compcount<<endl;
            
        }
        int max= 0;
        double ave = 0;
        for(int i =0;i<querynum;i++){
            if(max<comparisons[i]){max = comparisons[i];}
            ave=ave+comparisons[i];
        }
        ave=ave/querynum;
        outfile<<"Number of queries: "<<querynum<<endl;
        outfile<<"Maximum number of comparisons: "<<max<<endl;
        outfile<<"Average number of comparisons: "<<ave<<endl;
        
        infile.close();
        outfile.close();
        delete [] comparisons;
        
    }

    
    
    
    
    
}

void DictionaryAVLTree::containsit(BinaryNode *rootNode,string word, bool &boolr,int &compcount)const{
    
    if (!rootNode) {
        return;
    }
    else {
        compcount++;
        if (word < rootNode->item) {
        
            containsit( rootNode->leftChildPtr,word,boolr,compcount);
        }
        else if(word == rootNode->item)
        {
            boolr=true;
       
        }
        else {
            containsit(rootNode->rightChildPtr,word,boolr,compcount);
        }
    }
  
  
    
}
