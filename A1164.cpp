#include<bits/stdc++.h>
using namespace std;
string capital[27][8];
int main(){
    //A->Z
    string a;
    for(int i=0;i<26;i++){
        for(int j=0;j<7;j++){
            cin>>a;
            capital[i][j]=a;
        }
    }
    //getline()之前先用getchar()吸收换行符
    getchar();
    string s;
    getline(cin,s);
//    这道题是将句子分割成单词，
//    比如HELLO~WORLD!分割成HELLO和WORLD;
//    我这里的解决方法是遍历句子的字符同时用word存储单词，每次遇到A-Z就加入word，
//    否则说明到了该单词末尾，单词划分完成。
//    但这个是有问题的，如果最后一个字符也是字母，比如HELLO~WORLD，
//    那么WORLD被放入word之后，遍历会直接结束，最后一个单词无法处理。
//    所以人工加一个“#”号（其他非字母符号都可以）。
//    这种小坑pat也是有几道的，都是有可能无法处理最后一个单词导致测试点不能全部通过，然后找错误也不能很快找到。
//
//
// 还有的解决方法是，在循环完成之后，增加一个判断，判断word里是否还有单词，如果最后一个字符也是字母，word.size()>0。
// 一定要保证不能漏掉这种情况下的最后一个单词，否则测试点不能全部通过，影响考试心态。
//    s+="#";//让最后一个单词也能被处理~（当最后一个字符也是字母时）
    string word="";
    bool flag=false;
    // 遍历所有字符
    for(int i=0;i<s.size();i++){
        // 找到需要输出的
        if(s[i]>='A'&&s[i]<='Z'){
            word+=s[i];
        }else{
            //输出word
            // 不是第一次输出 先需要换行
            if (word.size() > 0 && flag) cout << endl;

            // 遍历可以输出的字符
            if(word.size()>0)
                for(int j=0;j<7;j++){
                    string ans;
                    for(int k=0;k<word.size();k++){
                        ans += capital[word[k] - 'A'][j];

                        if(k!=word.size()-1) ans+=" ";
                    }
                    cout<<ans<<endl;
                    // 第一行已经输出过了
                    // 下一次开始 就该先输出换行
                    flag=true;
                }
            //清空
            word.clear();
        }
    }
    return 0;
}