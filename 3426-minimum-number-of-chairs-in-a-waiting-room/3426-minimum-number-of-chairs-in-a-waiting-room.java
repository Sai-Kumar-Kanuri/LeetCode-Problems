class Solution {
    public int minimumChairs(String s) {
        Stack<Character> st = new Stack<Character>();

        int size = 0;

        for(char c : s.toCharArray()){
            if(c=='E'){
                st.push(c);
            }else{
                st.pop();
            }

            size = Math.max(size,st.size());
        }

        return size;
    }
}