class ServicesView : public Html {
        public:
                void buildContent() override {
                        addRawStyle(R"(
                                .container { max-width: 800px; margin: 50px auto; padding: 20px; background-color: #fff; box-shadow: 0 2px 4px rgba(0,0,0,0.1); }
                                h1#services { margin-bottom: 10px; text-align: center; }
                                p { line-height: 1.6; }
                                ul { list-style-type: disc; margin-left: 20px; }
                                li { margin-bottom: 5px; }
                        )");

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
