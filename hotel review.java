
       class check{
    public int index,count;
    public check(int i,int j)
    {
        index=i;
        count=j;
    }
    public static class countComp implements Comparator<check>{
        @Override
        public int compare(check c,check c1)
        {
            return ((Integer)c1.count).compareTo((Integer)c.count);
        }
    }
    public static final Comparator<check> COUNTCOMP=new countComp();
    }

public class Solution {

    static class TrieNode
    {
        TrieNode[] children = new TrieNode[26];
        boolean isEndOfWord;

        TrieNode(){
            isEndOfWord = false;
            for (int i = 0; i < 26; i++)
                children[i] = null;
        }
    };
        static TrieNode root;
        static void insert(String key)
       {
        int level;
        int length = key.length();
        int index;

        TrieNode pCrawl = root;

        for (level = 0; level < length; level++)
        {
            index = key.charAt(level) - 'a';
            if (pCrawl.children[index] == null)
                pCrawl.children[index] = new TrieNode();

            pCrawl = pCrawl.children[index];
        }
        pCrawl.isEndOfWord = true;
       }
       static boolean search(String key)
       {
        int level;
        int length = key.length();
        int index;
        TrieNode pCrawl = root;

        for (level = 0; level < length; level++)
        {
            index = key.charAt(level) - 'a';

            if (pCrawl.children[index] == null)
                return false;

            pCrawl = pCrawl.children[index];
        }

        return (pCrawl != null && pCrawl.isEndOfWord);
        }

    public ArrayList<Integer> solve(String A, ArrayList<String> B) {

    String ar[]=A.split("_");
    root=new TrieNode();
    int i;
    for(String y:ar)
    {
        insert(y);
    }
    ArrayList<check> a=new ArrayList<check>();
    i=0;
    for(String ob:B)
    {
        String x[]=ob.split("_");
        int count=0;
        for(String j:x)
        {
            if(search(j))
                count++;
        }
        check c1=new check(i,count);
        a.add(c1);
        i++;

    }
    Collections.sort(a,check.COUNTCOMP);
    ArrayList<Integer> res=new ArrayList<Integer>();

    for(check w:a)
    {
        res.add(w.index);
    }
    return res;
    }
}
