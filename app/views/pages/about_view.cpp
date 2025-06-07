class AboutView : public Html {
        public:
                AboutView(){ setTemplatePath("app/templates/layout.html"); }
                void buildContent() override {
                        addElementTag(R"(
                                <div class='container'>
                                        <h1 id='about'>About Us</h1>
                                        <p>This sample project demonstrates a basic C++ web framework.</p>
                                        <p>Our goal is to showcase how a familiar MVC approach can be expressed in a performant language.</p>
                                        <p>Feel free to explore the code and adapt it to your own needs.</p>
                                        <p><a href='/services'>See what we offer</a> or <a href='/contact'>reach out for more information</a>.</p>
                                </div>
                        )");
                }
};
