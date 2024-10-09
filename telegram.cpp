//
// Created by matcix on 2024/9/7.
//
#include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;

string sendTelegramMessage(const string &botToken, const string &chatId, const string &message)
{
    CURL *curl;
    CURLcode res;
    string readBuffer;

    curl = curl_easy_init();
    if (curl)
    {
        string url = "https://api.telegram.org/bot" + botToken + "/sendMessage?chat_id=" + chatId + "&text=" + curl_easy_escape(curl, message.c_str(), message.length());

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl,CURLOPT_USERAGENT, "libcurl-agent/1.0");

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK)
        {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        } else
        {
            return readBuffer;
        }
    }
      return "";
 }

int sendTelegram()
{
    string botToken = "你的机器人token";
    string chatId = "";
    string message = "散兵是三处的爹";

    string response = sendTelegramMessage(botToken, chatId, message);
    cout << "Response: " << response << endl;
    return 0;
}

