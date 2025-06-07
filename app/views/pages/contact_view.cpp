class ContactView : public Html {
        public:
                void buildContent() override {
                        addRawStyle(R"(
                                h1#contact { margin-bottom: 10px; text-align: center; }
                                form { display: flex; flex-direction: column; gap: 10px; }
                                label { font-weight: bold; }
                                input, textarea { padding: 8px; }
                        )");

                        addElementTag(R"(
                                <div class='container'>
                                        <h1 id='contact'>Contact Us</h1>
                                        <form>
                                                <label>Name</label>
                                                <input type='text' placeholder='Your Name'>
                                                <label>Message</label>
                                                <textarea rows='4' placeholder='Your Message'></textarea>
                                        </form>
                                </div>
                        )");
                }
};
