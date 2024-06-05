class Solution {
    public List<String> commonChars(String[] words) {

        int[] freq = new int[26];
        Arrays.fill(freq,Integer.MAX_VALUE);


        for(String word:words){
            int[] wordCnt = new int[26];

            for(char c:word.toCharArray()){
                wordCnt[c-'a']++;
            }
            for(int i=0;i<26;i++){
                freq[i]=Math.min(freq[i],wordCnt[i]);
            }
        }

        List<String> res = new ArrayList<>();
        for(int i=0;i<26;i++){
            while(freq[i]>0){
                res.add(Character.toString((char)(i+'a')));
                freq[i]--;
            }
        }

        return res;




    }
}