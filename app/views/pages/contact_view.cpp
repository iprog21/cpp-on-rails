class ContactView : public Html {
        public:
                void buildContent() override {
                        addRawStyle(R"(
                                .container { max-width: 800px; margin: 50px auto; padding: 20px; background-color: #fff; box-shadow: 0 2px 4px rgba(0,0,0,0.1); }
                                h1#contact { margin-bottom: 10px; text-align: center; }
                                p { line-height: 1.6; text-align: center; }
                                form { display: flex; flex-direction: column; gap: 10px; }
                                label { font-weight: bold; }
                                input, textarea { padding: 8px; }
                        )");

                        addElementTag(R"(
                                <div class='container'>
                                        <h1 id='contact'>Contact Us</h1>
                                        <p>Have questions or feedback? Drop us a message below.</p>
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
