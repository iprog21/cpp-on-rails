class HomeView : public Html {
        public:
                void buildContent() override {
                        addRawStyle(R"(
                                .container { max-width: 800px; margin: 50px auto; padding: 20px; text-align: center; background-color: #fff; box-shadow: 0 2px 4px rgba(0,0,0,0.1); }
                                h1#home { margin-bottom: 10px; }
                                p { line-height: 1.6; }
                        )");

                        addElementTag(R"(
                                <div class='container'>
                                        <h1 id='home'>Welcome to C++ on Rails</h1>
                                        <p>Explore the sample application built with C++.</p>
                                </div>
                        )");
                }
};
