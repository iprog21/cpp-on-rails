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
                                </div>
                        )");
                }
};
