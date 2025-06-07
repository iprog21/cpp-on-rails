class NotFoundView : public Html {
	public:
		void buildContent() override {
			addRawStyle(R"(
				.container { max-width: 600px; margin: 50px auto; padding: 20px; background-color: #fff; box-shadow: 0 2px 4px rgba(0,0,0,0.1); }
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
