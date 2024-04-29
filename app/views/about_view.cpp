#include "./../../app/services/Html.h"
class AboutView : public Html {
	public:
		void buildContent() override {
			addStyle("h1#about", "padding-left", "5px");
			addElementTag("<h1 id='about'>About Page</h1>");
		}
};