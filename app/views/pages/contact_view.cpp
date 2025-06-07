class ContactView : public Html {
	public:
		void buildContent() override {
			addStyle("h1#contact", "padding-left", "15px");
			addElementTag("<h1 id='contact'>Contact Page</h1>");
		}
};
