class ServicesView : public Html {
        public:
                void buildContent() override {
                        addRawStyle(R"(
                                h1#services { margin-bottom: 10px; text-align: center; }
                                ul { list-style-type: disc; margin-left: 20px; }
                                li { margin-bottom: 5px; }
                        )");

                        addElementTag(R"(
                                <div class='container'>
                                        <h1 id='services'>Our Services</h1>
                                        <ul>
                                                <li>Web application development</li>
                                                <li>Consulting</li>
                                                <li>Support & maintenance</li>
                                        </ul>
                                </div>
                        )");
                }
};
