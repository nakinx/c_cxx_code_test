/*
 * MIT License
 *
 * Copyright (c) 2019 Ismael Filipe Mesquita Ribeiro - nakinx
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <iostream>
#include <string>
#include <string.h>
#include <curl/curl.h>

class Page {

public:
    Page() {};

    ~Page() {};

    void LoadPage(const std::string & url) {
        CURL * curl;
        CURLcode rc;

        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();

        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

            // Refuse to download if larger than 4096 bytes.
            curl_easy_setopt(curl, CURLOPT_MAXFILESIZE, 4096L);

            // Send all data to this the function.
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &Page::StorePageIntoMemory);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &_pageBuffer);

            // Perform the request.
            rc = curl_easy_perform(curl);

            // Check for errors.
            if (rc != CURLE_OK)
                fprintf(stderr, "Error during perform: (%s)\n", curl_easy_strerror(rc));

            curl_easy_cleanup(curl);
            curl_global_cleanup();
        }
    }

    std::string getPage() {
        return _pageBuffer;
    }

private:

    size_t static StorePageIntoMemory(char * data,
                                      size_t size,
                                      size_t nmemb,
                                      std::string * writer) {
        int total_size = 0;

        if (writer != nullptr) {
            writer->append(data, (size * nmemb));
            total_size = (size * nmemb);
        }

        return total_size;
    }

    std::string _pageBuffer;
};


int main(int argc,
         char * argv []) {

    std::cout << "Starting application...\n\n";

    Page p;

    p.LoadPage("http://www.example.com/");

    std::cout << "\nPage: (" << p.getPage() << ")\n";

    std::cout << "Application ended...\n\n";

    return 0;
}