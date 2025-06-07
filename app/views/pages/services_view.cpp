class ServicesView : public Html {
        public:
                ServicesView(){ setTemplatePath("app/templates/layout.html"); }
                void buildContent() override {
                        addElementTag(R"(
                                <div class='container'>
                                        <h1 id='services'>Our Services</h1>
                                        <p>Below are some example components provided by this framework:</p>
                                        <ul>
                                                <li>Web application development</li>
                                                <li>Consulting</li>
                                                <li>Support &amp; maintenance</li>
                                        </ul>
                                        <p>Interested in using C++ for your project? <a href='/contact'>Contact us</a> today.</p>
                                </div>
                        )");
                }
};
