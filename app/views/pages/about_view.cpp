class AboutView : public Html {
	public:
		void buildContent() override {
			addStyle("h1#about", "padding-left", "15px");
			addElementTag("<h1 id='about'>About Page</h1>");
		}
};