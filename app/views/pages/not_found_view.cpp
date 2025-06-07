class NotFoundView : public Html {
        public:
                NotFoundView(){ setTemplatePath("app/templates/layout.html"); }
                void buildContent() override {
                        addElementTag(R"(
                                <div class="container">
                                        <h1>404 Not Found</h1>
                                        <p>Sorry, the page you are looking for does not exist. You can always go back to the <a href="/">homepage</a>.</p>
                                </div>
                        )");
		}
};
