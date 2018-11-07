#include<bits/stdc++.h>
using namespace std;
string str[20];
int use[20], length = 0, n;

bool cover(string str1, string str2, int len){
	for (int i = 0; i < len; i++){
		if (str1[str1.length()-len+i] != str2[i]) return false;
	}
	return true;
}

int canlink(string str1, string str2){
	for (int i = 1; i < min(str1.length(), str2.length()); i++){
		if (cover(str1, str2, i)) return i;
	}
	return 0;
}

void solve(string strnow, int lengthnow) {
    length = max(lengthnow, length);//������󳤶�
    
    for(int i = 0; i < n; i++) {
        if(use[i] >= 2) continue;//���ַ���ʹ�ô�����ҪС��2
        int c = canlink(strnow, str[i]);//��ȡ�ص�����
        if(c > 0) {//���ص����־Ϳ�ʼdfs
            use[i]++;
            solve(str[i], lengthnow + str[i].length() - c);
            use[i]--;
        }
    }
}

main() {
    cin >> n;
    for(int i = 0; i <= n; i++) use[i] = 0, cin >> str[i];//str[n]Ϊ��ʼ�ַ� 
    solve(' '+str[n], 1);//�б�Ҫ����һ�¿�ʼ�׶Ρ�Ϊ��ָ����һ���ַ���������Ϊcanlink��Ҫ�ص�����С����̳���-1������Ҫ��ǰ�����һ��������䳤�ȵġ� ����������ǿ����canlink�����Ƚ����һλ��
    cout << length ;
}
