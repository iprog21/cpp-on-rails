# C++ on Rails Web Framework by [IPROG TECH](https://iprog.tech)

C++ on Rails is a lightweight and efficient web framework inspired by Ruby on Rails and CodeIgniter, designed to simplify the development of web applications using C++.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Disclaimer

C++ on Rails is not affiliated with or endorsed by the creators of Ruby on Rails. "Rails" is a registered trademark of Basecamp, LLC. The use of the term "on Rails" in the name of this project is intended to convey a structured and guided approach to web development, similar to that of Ruby on Rails.

## How to use
1. Clone the repo
2. Run `make` to build the executable (requires a C++17 compiler).
3. Run `make clean` to remove the compiled binary and force a rebuild using the `clean` target.
4. Execute `./cpp-on-rails` to start the sample server.

## Running tests

Run the test suite using `make`:

```bash
make test
```

## Custom styles

The framework automatically loads `public/styles/main.css` and inlines its
contents into each page. Modify this file to adjust colors, fonts or any other
CSS rules and rebuild the project to see the changes.

