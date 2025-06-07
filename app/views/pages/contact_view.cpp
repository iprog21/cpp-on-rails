class ContactView : public Html {
        public:
                ContactView(){ setTemplatePath("app/templates/layout.html"); }
                void buildContent() override {
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
