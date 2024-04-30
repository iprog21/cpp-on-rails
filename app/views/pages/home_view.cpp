class HomeView : public Html {
	public:
		void buildContent() override {
			addStyle("h1#home", "padding-left", "15px");
			addElementTag("<h1 id='home'>Home Page</h1>");
		}
};