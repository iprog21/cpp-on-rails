class NotFoundView : public Html {
	public:
		void buildContent() override {
                        addRawStyle(R"(
                                h1 { color: #d3381c; }
                                p { line-height: 1.6; }
                                a { color: #d3381c; text-decoration: none; }
                                a:hover { text-decoration: underline; }
                        )");

			addElementTag(R"(
				<div class="container">
					<h1>404 Not Found</h1>
					<p>Sorry, the page you are looking for does not exist. You can always go back to the <a href="/">homepage</a>.</p>
				</div>
			)");
		}
};
