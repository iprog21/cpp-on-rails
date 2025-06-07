#include <string>
#include <chrono>
#include <vector>
#include <map>
#include <unordered_map>
#include <regex>
#include "template.cpp"
#include <fstream>

class Html {
	struct KeyValuePair { std::string element, key, value; };
	std::string site_title, footer_title;
	std::vector<KeyValuePair> styles;
	std::vector<std::string> raw_styles;
	std::vector<std::string> scripts;
        std::vector<std::string> element_tags;
        std::string template_path;

	public:
		Html(){
			setSiteTitle("C++ on Rails");
			setFooterTitle("@ " + getCurrentYear() + " C++ on Rails.");
			setDefaultStyles();
			setDefaultScripts();
			setDefaultElementTags();
		}

		virtual void buildContent(){}

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

                void setTemplatePath(std::string path){
                        template_path = path;
                }

		void setDefaultStyles(){
			addStyle("body", "background-color", "#fff");
			addStyle("body", "margin", "0");
			addStyle("body", "font-family", "Arial, sans-serif");
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
			addStyle(".container", "max-width", "800px");
			addStyle(".container", "margin", "50px auto");
			addStyle(".container", "padding", "20px");
			addStyle(".container", "background-color", "#fff");
			addStyle(".container", "box-shadow", "0 2px 4px rgba(0,0,0,0.1)");
                        addStyle(".navbar", "background-color", "#333");
			addStyle(".navbar", "overflow", "hidden");
			addStyle(".navbar-brand", "float", "left");
			addStyle(".navbar-brand", "display", "block");
			addStyle(".navbar-brand", "padding", "15px 20px");
			addStyle(".navbar-brand", "color", "#fff");
			addStyle(".navbar-brand", "text-decoration", "none");
			addStyle(".navbar-brand", "font-size", "20px");
			addStyle(".navbar-menu", "float", "right");
			addStyle(".navbar-menu ul", "list-style-type", "none");
			addStyle(".navbar-menu ul", "margin", "0");
			addStyle(".navbar-menu ul", "padding", "0");
			addStyle(".navbar-menu ul", "overflow", "hidden");
			addStyle(".navbar-menu li", "float", "left");
			addStyle(".navbar-menu li a", "display", "block");
			addStyle(".navbar-menu li a", "padding", "15px 20px");
			addStyle(".navbar-menu li a", "color", "#fff");
			addStyle(".navbar-menu li a", "text-decoration", "none");
                        addStyle(".navbar-menu li a:hover", "background-color", "#555");
                        loadCssFile("public/styles/main.css");
                }

		void setDefaultScripts(){
				addScript(defaultScript());
		}

		void setDefaultElementTags(){
			addElementTag(defaultNavBar());
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

		virtual std::string defaultNavBar(){
			return R"(
				<div class='navbar'>
					<a href='/' class='navbar-brand'>C++ on Rails</a>
					<div class='navbar-menu'>
							<ul>
											<li><a href='/'>Home</a></li>
											<li><a href='/about'>About</a></li>
											<li><a href='/services'>Services</a></li>
											<li><a href='/contact'>Contact</a></li>
							</ul>
					</div>
				</div>
			)";
		}

		void addStyle(std::string element, std::string key, std::string value){
			 KeyValuePair pair;
				pair.element = element;
				pair.key = key;
				pair.value = value;

				styles.push_back(pair);
		}

                void addRawStyle(std::string style){
                        raw_styles.push_back(style);
                }

                void loadCssFile(const std::string& path){
                        std::ifstream file(path);
                        if(file){
                                std::string contents((std::istreambuf_iterator<char>(file)),
                                                    std::istreambuf_iterator<char>());
                                raw_styles.push_back(contents);
                        }
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
"<meta name='viewport' content='width=device-width, initial-scale=1'>\n"
													"</head>\n"
													"<body>\n";
		}

		std::string generateContent() {
			std::string compiled_element_tags;

			for(const auto& element_tag : element_tags)
				compiled_element_tags += element_tag;

			removeExtraSpaces(compiled_element_tags);

			return compiled_element_tags;
		}

                std::string generateFooter() {
                        return "\n<footer>\n" + footer_title + "\n</footer>\n"
                                       + generateScripts()
                                       + "</body></html>\n";
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

				// raw styles
				for(const auto& raw_style : raw_styles)
					compiled_styles += raw_style;

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
                        if(template_path.empty())
                                return generateHeader() + generateContent() + generateFooter();

                        Template tpl(template_path);
                        tpl.replace("title", site_title);
                        tpl.replace("styles", generateStyles());
                        tpl.replace("content", generateContent());
                        tpl.replace("footer", footer_title);
                        tpl.replace("scripts", generateScripts());
                        return tpl.render();
                }

		void removeExtraSpaces(std::string& str) {
    std::regex regex("\\s+");
    str = std::regex_replace(str, regex, " ");
    str = std::regex_replace(str, std::regex("^\\s+|\\s+$"), "");
  }
};
