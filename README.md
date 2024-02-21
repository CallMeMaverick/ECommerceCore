# 👨🏻‍💻🛍️ ECommerceCore

**ECommerceCore** is the final exam project for the Advanced Object-Oriented Programming (OOP) course in C++ at IT Step Computer Academy. It is designed to showcase a culmination of skills and concepts learned throughout the course.

## 📚 Description
This console application serves as the backend of an e-commerce platform, simulating real-world functionality while embodying essential OOP principles, design patterns, and modern C++ best practices.

## 🎯 Focus:
**OOP Principles**: The project is all about using OOP principles like inheritance, polymorphism, encapsulation, and abstraction. It's structured to make the code easy to read, update, and manage.

**Handle Complex JSON**: Efficiently parse and process complex JSON data using a suitable library [nlohmann::json](https://github.com/nlohmann/json). Validate incoming JSON against a schema to ensure data integrity.

**Design Patterns and C++ Features**: The project utilizes different design patterns and modern C++ features to make the code better. This includes things like smart pointers for memory management and the Standard Template Library (STL) for working with data.

**Incorporate Best Practices**: Adhere to C++ style guides (e.g., [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)) for consistent formatting and readability.


## 🦾 Main Features

* **Approach to storing user data using JSON** </br> ---> *It is important to note that this method is not secure and should not be implemented in real-world applications. The information displayed is purely for illustrative purposes and does not represent actual user accounts; similarly, the application utilizes this approach exclusively for academic purposes* <---

```json
{
    "a": [
        {
            "password": "99@tOHL9wdmXs",
            "username": "sludchpo"
        }
    ],
    "b": [
        {
            "password": "99@VkZeC79JvE",
            "username": "vuyclglx"
        }
    ],
    "c": [
        {
            "password": "99@ouDAbzZ%gu",
            "username": "hbvmdgwf"
        }
    ]
}
```
* **Signing up / logging in** </br> *Example of logging in process:*
```cpp
// Validate both username and password
        try {
            validateName(username);
            validatePassword(password);
        }
        catch (const std::invalid_argument& exception) {
            // Here it states that user doesn't exist because if, when signing up,
            // user didn't pass the validation, they could not register,
            // so invalid usernames or passwords are not in auth.json
            throw std::invalid_argument("User does not exist");
        }

        std::ifstream jsonFileRead("...");
        json readData;
        if (jsonFileRead.is_open())
        {
            try {
                jsonFileRead >> readData;
                jsonFileRead.close();
            }
            catch (json::parse_error& e) {
                std::cout << e.what() << std::endl;
                throw;
            }

            // If data has been read, proceed by iterating over JSON object
            for (auto& [key, user] : readData.items())
            {
                // Compare the key (which is the letter we group users by),
                // with the first letter of given username
                if (key[0] == username[0])
                {
                    // If found, now iterate over JSON object,
                    // and compare username and password given with those object has
                    for (auto& userData : user)
                    {
                        if (userData["username"] == username && userData["password"] == password)
                        {
                            return true;  // <-- return true if user has been found
                        }
                    }

                    std::cout << "User hasn't been found" << std::endl;
                    return false;  // <-- return false if user hasn't been found
                }
            }
        }
        return false;  // <-- return false if user hasn't been found
    }
```
*Please again note that in this case, for instance, the absolute path to the catalog is not encapsulated and secured due to the reasons discussed in the first feature*

## ⚙️ Building

### MacOS / Linux
* Open the terminal in the project directory.
* Generate CMake build files; use: </br>
`cmake ..`

### Windows 
* `cmake -G "Visual Studio 17"` to generate Visual Studio solution files.
* Instead of -G Visual Studio 17, you can use `-G "MinGW Makefiles"`. This generates Makefiles compatible with MinGW, a free and open-source C/C++ compiler suite for Windows. Users can then build the project using a command-line tool like mingw32-make.

Once the build files are generated, you can proceed to build and run your application.

### Note: 
* For detailed build instructions and troubleshooting, refer to the [CMake documentation](https://cmake.org/)
* If you encounter issues, search online forums or communities for help with CMake specifically on your platform.

## 🤝 Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

### Before You Contribute:
**Review the coding style**: Familiarize yourself with coding conventions to ensure consistency.</br>
**Fork the repository**: Create a personal fork of the repository to work on your changes.</br>
**Open an issue (*optional*)**: For major changes, discuss your ideas in an issue before starting a pull request.</br>
**Write clear commit messages**: Use descriptive commit messages that explain your changes.</br>
**Test your changes**: Ensure your contributions don't break existing functionality. Write or update tests as needed.</br>



## 📄 License

MIT License - *see LICENSE for details*

Copyright (c) 2024 Kushnierov Sviatoslav

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
