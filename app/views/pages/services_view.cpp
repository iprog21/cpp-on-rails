class ServicesView : public Html {
	public:
		void buildContent() override {
			addStyle("h1#services", "padding-left", "15px");
			addElementTag("<h1 id='services'>Services Page</h1>");
		}
};
