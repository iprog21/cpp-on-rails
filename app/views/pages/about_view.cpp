class AboutView : public Html {
        public:
                void buildContent() override {
                        addRawStyle(R"(
                                h1#about { margin-bottom: 10px; text-align: center; }
                                p { line-height: 1.6; }
                        )");

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
