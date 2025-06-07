#include "test_framework.h"
#include "../app/services/html.cpp"
#include "../app/views/pages/home_view.cpp"

TEST_CASE(TestHomeViewBuildHtml){
    HomeView view;
    view.buildContent();
    std::string html = view.buildHtmlPage();
    REQUIRE(html.find("<html>") != std::string::npos);
    size_t pos = 0; int count = 0;
    while((pos = html.find("</body>", pos)) != std::string::npos){
        count++; pos += 7;
    }
    REQUIRE(count == 1);
}

int main(){
    return runTests();
}
