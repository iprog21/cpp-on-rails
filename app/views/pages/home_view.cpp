class HomeView : public Html {
        public:
                void buildContent() override {
                        addRawStyle(R"(
                                h1#home { margin-bottom: 10px; }
                                p { line-height: 1.6; }
                                ul { list-style-type: disc; margin: 15px auto; text-align: left; display: inline-block; }
                                li { margin-bottom: 5px; }
                        )");

                        addElementTag(R"(
                                <div class='container'>
                                        <h1 id='home'>Welcome to C++ on Rails</h1>
                                        <p>Explore the sample application built with C++.</p>
                                        <p>This demo shows how traditional MVC ideas can translate to modern C++.</p>
                                        <ul>
                                                <li>Lightweight structure</li>
                                                <li>Reusable view components</li>
                                                <li>Simple routing</li>
                                        </ul>
                                        <p><a href='/about'>Learn more</a> or <a href='/contact'>get in touch</a>.</p>
                                </div>
                        )");
                }
};
