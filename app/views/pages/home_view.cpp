class HomeView : public Html {
        public:
                void buildContent() override {
                        addRawStyle(R"(
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
