//
//  Dictionary23Tree.cpp
//  scs202hw3
//
//  Created by Zeynep Büsra Ziyagil on 19.07.2021.
//

#include <stdio.h>
#include "Dictionary23Tree.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
void Dictionary23Tree::insert(string word){
    
        if (this->size == 0) {
            this->root = new Two3Node;
            this->root->firstitem = word;
            this->size++;
            return;
        }
        Two3Node *n = this->root;
        // Find proper leaf node
        while (!n->leaf) {
            if (word.compare(n->firstitem) < 0) {
                n = n->first;
            } else if (!n->full || word.compare(n->seconditem) < 0) {
                n = n->second;
            } else {
                n = n->third;
            }
        }

        if (n->full)
            split(n, word, NULL, NULL, NULL, NULL);
        else {
            if (word.compare(n->firstitem) < 0) {
                n->seconditem = n->firstitem;
                n->firstitem = word;
            } else {
                n->seconditem = word;
            }
            n->full = true;
        }
        this->size++;
 
}
void Dictionary23Tree::split(Two3Node *n, string key, Two3Node *first, Two3Node *second, Two3Node *third, Two3Node *fourth){
    
    
    
    Two3Node *n1 = new Two3Node, *n2 = new Two3Node;
    Two3Node *p = n == this->root ? new Two3Node : n->parent;

    // Get the keys in order
    string min = n->firstitem, mid = n->seconditem, max;
    if (key.compare(min) < 0) {
        max = mid;
        mid = min;
        min = key;
    } else if (key.compare(mid) < 0) {
        max = mid;
        mid = key;
    } else {
        max = key;
    }

    n1->firstitem = min;
    n2->firstitem = max;
    n1->parent = p;
    n2->parent = p;

    if (!n->leaf) {
        n1->first = first;
        n1->second = second;
        n2->first = third;
        n2->second = fourth;

        first->parent = n1;
        second->parent = n1;
        third->parent = n2;
        fourth->parent = n2;

        n1->leaf = n2->leaf = false;
    }

    if (n == this->root) {
        p->firstitem = mid;
        p->first = n1;
        p->second = n2;
        p->leaf = false;
        this->root = p;
    } else if (p->full) {
        if (n == p->first) {
            split(p, mid, n1, n2, p->second, p->third);
        } else if (n == p->second) {
            split(p, mid, p->first, n1, n2, p->third);
        } else {
            split(p, mid, p->first, p->second, n1, n2);
        }
    } else {
        
        if (mid.compare(p->firstitem) < 0 ) {
            p->seconditem = p->firstitem;
            p->firstitem = mid;

            p->third = p->second;
            p->second = n2;
            p->first = n1;
        } else {
            p->seconditem = mid;

            p->second = n1;
            p->third = n2;
        }
        p->full = true;
    }
    delete n;
}


//Searches the given word in the dictionary, and returns the number
//of comparisons made and whether the word is found or not
void Dictionary23Tree::search( string word, int& numComparisons, bool& found ) const{
    found =false;

    int count =0;
    searchHelper(root, word, found,count); 
    
    numComparisons = count;
}
//Searches all words in the query file in the dictionary, and
//summarizes the results in the output file
void Dictionary23Tree::search( string queryFile, string outputFile ) const{
    
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


void Dictionary23Tree::searchHelper(Two3Node* curr, const string & word, bool & val,int &count) const{
    if (curr){
        count++;
        if (curr->firstitem.compare(word) == 0 ){
            val = true;
            
        }
        else if( curr->seconditem.compare(word) == 0 ){
            val = true;
            count++;
           
        }
        else{ 
            
            if (word.compare(curr->firstitem )<0){
                
            
                searchHelper(curr->first, word, val,count);
            }
            else if (word.compare(curr->seconditem )<0){
          
                count++;
                searchHelper(curr->second, word, val,count);
            }
            else if (curr->seconditem == ""){
                
                searchHelper(curr->second, word, val,count);
            }
            else{
                count++;
                searchHelper(curr->third, word, val,count);
                
            }
        }
    }
}
