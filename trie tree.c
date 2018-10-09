#include<stdio.h>
#include <stdbool.h>
typedef struct trie
{
 struct trie *ar[26];
 bool isEndOfWord;
}trie;

trie* createnode()
{
 trie *nn=(trie*)malloc(sizeof(trie));
 int i;
 for(i=0;i<26;i++)
 nn->ar[i]=NULL;
 nn->isEndOfWord=false;
 return nn;
}

void insert(trie *root,const char  *str)
{

 int index,i;
 for(i=0;i<strlen(str);i++)
 {
     index=str[i]-'a';
     if(!root->ar[index])
        root->ar[index]=createnode();
     root=root->ar[index];
 }
 root->isEndOfWord=true;
}


bool search(trie *root, char str[], int index) {
	if(index == strlen(str)) {
		if(!root->isEndOfWord)
			return false;
		return true;
	}
	int j = str[index] - 'a';
	if(!root->ar[j])
		return false;
	return search(root->ar[j], str, index+1);
}

bool deleted(trie *root, char str[], int index) {
	if(index == strlen(str)) {
		if(!root->isEndOfWord)
			return false;
		root->isEndOfWord = false;
		int i;
		for(i=0;i<26;i++)
			if(root->ar[i])
				return false;
		return true;
	}

	int j = str[index] - 'a';
	bool var = deleted(root->ar[j], str, index+1);
	if(var) {
		root->ar[j] = NULL;
		if(root->isEndOfWord)
			return false;
		else {
			int i;
			for(i=0;i<26;i++)
				if(root->ar[j])
					return false;
			return true;
		}
	}
	return false;
}
int main()
{
 char s1[]="hello";
 char s2[]="hell";
 char s3[]="peek";
 char s4[]="point";
 trie *root=createnode();
 int i;
 insert(root,s1);
 insert(root,s2);
 insert(root,s3);
 insert(root,s4);
 printf("%d\n",search(root,"pek",0));
 printf("%d\n",deleted(root,"peek",0));
}
