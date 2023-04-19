#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Trie
{
    int count;
    struct Trie *children[26];
};

void insert(struct Trie **ppTrie, char *word)
{
    if(*ppTrie == NULL)
    {
        return;
    }
    int length = strlen(word);
    struct Trie *temp = *ppTrie;
    for(int i = 0; i < length; i++)
    {
        int index = word[i] - 'a';
        if(temp->children[index] == NULL)
        {
             temp->children[index] = (struct Trie*)calloc(1, sizeof(struct Trie));
        }
        temp = temp->children[index];
    }
    temp->count = temp->count + 1;
    /*
    int wordLength = strlen(word);
    char wordToInsert[wordLength];
    struct Trie *newNode = (struct Trie*)malloc(sizeof(struct Trie));
    newNode = ppTrie;
    for(int i = 0; i < wordLength; i++)
    {
        if(newNode->children[wordToInsert[i] - 'a'] != NULL)
        {
            newNode = newNode->children[wordToInsert[i] - 'a'];
        }
        else
        {
            struct Trie *newChild = (struct Trie*)malloc(sizeof(struct Trie));
            newChild = newNode;
            if(wordLength == i + 1)
            {
                newChild->count = newChild->count + 1;
            }
        }
    }
    */
    

}
int numberOfOccurances(struct Trie *pTrie, char *word)
{
     if(pTrie == NULL)
    {
        return 0;
    }
    int length = strlen(word);
    int numOfOccur;
    struct Trie *temp = pTrie;
    for(int i = 0; i < length; i++)
    {
        int index = word[i] - 'a';
        if(i == length - 1)
        {
            numOfOccur = temp->children[index]->count;
        }
        temp = temp->children[index];
    }
    return numOfOccur;
}
struct Trie *deallocateTrie(struct Trie *pTrie)
{
 int i;
    for(i = 0; i < 26; i++)
    {
        if(pTrie->children[i] != NULL)
        {
            deallocateTrie(pTrie->children[i]);
        }
    }
 free(pTrie);
}
int main(void)
{
      //read the number of the words in the dictionary
      // parse line  by line, and insert each word to the trie data structure
      struct Trie *trie = (struct Trie*)calloc(1,sizeof(struct Trie));
      char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
      for(int i = 0; i < 6; i++)
      {
        insert(&trie, pWords[i]);
      }
      for (int i=0;i<6;i++)
      {
          printf("\t%s : %d\n",pWords[i], numberOfOccurances(trie, pWords[i]));
      }
    trie = deallocateTrie(trie);
    if (trie != NULL)
       printf("There is an error in this program\n");
    return 0;
}