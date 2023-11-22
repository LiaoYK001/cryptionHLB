#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int strlen(const char* str) //计算字符串长度
{
    const char* s = str; // 用于遍历字符串的指针 用const防止意外修改
    int length = 0; // 用于存储字符串长度的变量
    while (s[length] != '\0') length++;//出现\0表明字符串结束
    return length; // 返回字符串长度
}

void decrypt(char* str, char* key) // 函数用于执行异或解密
{
    int len = strlen(str);  // 计算密文长度
    char decrypt[200];  // 解码result，假设长度最大为 200
    printf("\n\n再次异或（解码）：\n");
    for (int i = 0; i < len; i++)
    {
        char encryptedChar = str[i] ^ key[i % strlen(key)];  // 使用异或运算解码单个字符
        printf("%c", encryptedChar);  // 打印解码后的字符
    }
    printf("\n\n");
}


void encrypt(char* str, char* key) // 函数用于执行异或加密
{
    int len = strlen(str);  // 计算明文长度
    char first_encrypt[200];  // 创建一个数组用于存储第一次加密后的结果，假设长度最大为 200
    printf("\n\n加密后：\n");
    // 第一次异或运算并打印结果

    for (int i = 0; i < len; i++)
    {
        char encryptedChar = str[i] ^ key[i % strlen(key)];  // 使用异或运算加密单个字符
        if (encryptedChar < 32 || encryptedChar > 126) {
            printf("?");// 如果加密后的字符不在可打印范围内，将其替换为问号
        }
        else {
            printf("%c", encryptedChar);  // 打印加密后的字符
        }
        first_encrypt[i] = encryptedChar;  // 将第一次加密的结果存储在数组中
        first_encrypt[len] = '\0';
    }
    printf("\n\n");
    decrypt(first_encrypt, key);
}



int main() {
    printf("请输入一段文字(不超过200)：\n");
    char plaintext[200];
    gets_s(plaintext);
    printf("数字密钥0~9(不超过20)：\n");
    char key[20];
    gets_s(key);
    printf("加密前：\n%s\n\n", plaintext);  // 打印原始文本
    encrypt(plaintext, key);  // 调用加密函数
    getchar();
    return 0;
}