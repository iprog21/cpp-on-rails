#ifndef HTML_H
#define HTML_H

#include <string>
#include <chrono>
#include <vector>
#include <map>
#include <unordered_map>
#include <regex>

class Html {
	struct KeyValuePair {
  std::string element, key, value;
 };
	std::string site_title, footer_title;
	std::vector<KeyValuePair> styles;
	std::vector<std::string> scripts;
	std::vector<std::string> element_tags;

	public:
		Html(){
			setSiteTitle("C++ on Rails");
			setFooterTitle("@ " + getCurrentYear() + " C++ on Rails.");
			setDefaultStyles();
			setDefaultScripts();
			setDefaultElementTags();
		}

		std::string getCurrentYear() {
    std::time_t currentTime = std::time(nullptr);
    std::tm *timeinfo = std::localtime(&currentTime);
    int year = timeinfo->tm_year + 1900;

    return std::to_string(year);
		}

		void setSiteTitle(std::string title){
			site_title = title;
		}

		void setFooterTitle(std::string title){
			footer_title = title;
		}

		void setDefaultStyles(){
			addStyle("body", "background-color", "#fff");
			addStyle("body", "margin", "0");
			addStyle("body", "padding-bottom", "100px");
			addStyle("body", "display", "flex");
			addStyle("body", "flex-direction", "column");
			addStyle("body", "min-height", "10vh");
			addStyle("footer", "background-color", "#333");
			addStyle("footer", "color", "#fff");
			addStyle("footer", "padding", "15px");
			addStyle("footer", "position", "fixed");
			addStyle("footer", "bottom", "0");
			addStyle("footer", "width", "100%");
			addStyle(".hidden", "display", "none");
		}

		void setDefaultScripts(){
				addScript(defaultScript());
		}

		void setDefaultElementTags(){
			addElementTag(defaultElementTag());
		}

		std::string defaultScript(){
			return R"(
				window.onload = function() {
					console.log('C++ on Rails.');
				};
			)";
		}

	 std::string defaultElementTag(){
			return R"(
				<h1 class='hidden'>C++ on Rails.</h1>
			)";
		}

		void addStyle(std::string element, std::string key, std::string value){
			 KeyValuePair pair;
				pair.element = element;
				pair.key = key;
				pair.value = value;

				styles.push_back(pair);
		}

		void addScript(std::string script){
			scripts.push_back(script);
		}

		void addElementTag(std::string element_tag){
			element_tags.push_back(element_tag);
		}

		void clearBodyContent(){
			element_tags.clear();
			element_tags.shrink_to_fit();
		}

		std::string generateHeader() {
						return "<!DOCTYPE html>\n"
													"<html>\n"
													"<head>\n"
													"<title>" + site_title + "</title>\n"
													+ generateStyles() +
													"</head>\n"
													"<body>\n";
		}

		std::string generateContent() {
			std::string compiled_element_tags;

			for(const auto& element_tag : element_tags)
				compiled_element_tags += element_tag;

			removeExtraSpaces(compiled_element_tags);

			return "<main>" + compiled_element_tags + "</main>\n";
		}

		std::string generateFooter() {
						return "</body>\n<footer>\n" + footer_title + "\n</footer>\n"
													+ generateScripts() +
													"</body>\n"
													"</html>\n";
		}

		std::string generateStyles() {
			std::string compiled_styles;
			std::unordered_map<std::string, std::vector<KeyValuePair>> groupedStyles;

			for (const auto& style : styles)
					groupedStyles[style.element].push_back(style);

   for (const auto& pair : groupedStyles) {
					compiled_styles += pair.first + "{";
					for (const auto& style : pair.second)
						compiled_styles += style.key + ":" + style.value + ";";
					compiled_styles += "}";
    }

			removeExtraSpaces(compiled_styles);

			return "<style type='text/css'>" + compiled_styles + "</style>\n";
		}

		std::string generateScripts() {
			std::string compiled_scripts;
			for(const auto& script : scripts)
				compiled_scripts += script;

			removeExtraSpaces(compiled_scripts);

			return "<script>" + compiled_scripts + "</script>\n";
		}

		std::string buildHtmlPage(){
			return generateHeader() + generateContent() + generateFooter();
		}

		virtual void buildContent(){}

		void removeExtraSpaces(std::string& str) {
    std::regex regex("\\s+");
    str = std::regex_replace(str, regex, " ");
    str = std::regex_replace(str, std::regex("^\\s+|\\s+$"), "");
  }
};
#endif // HTML_H
