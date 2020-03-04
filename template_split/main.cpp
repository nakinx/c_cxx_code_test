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
#include <vector>
#include <list>

#include "template_split.h"

int main(int argc,
         char * argv[])
{
    std::vector<std::string> vnonstatictest;
    std::list<std::string> lstatictest;

    std::string name = "Ismael Filipe Mesquita Ribeiro";

    TemplateSplit ts(name);

    ts.Split(vnonstatictest, ' ');

    std::cout << "Original string: (" << name << ")\n";
    std::cout << "Using split string with <vector>: \n";

    for (auto item : vnonstatictest) {
        std::cout << "item: " << item << "\n";
    }

    TemplateSplit::Split(name, lstatictest, ' ');

    std::cout << "Using static split with <list>: \n";

    for (auto item : lstatictest) {
        std::cout << "item: " << item << "\n";
    }

    return 0;
}