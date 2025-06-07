class AboutView : public Html {
        public:
                void buildContent() override {
                        addRawStyle(R"(
                                .container { max-width: 800px; margin: 50px auto; padding: 20px; background-color: #fff; box-shadow: 0 2px 4px rgba(0,0,0,0.1); }
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
