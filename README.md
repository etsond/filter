# Image Filter Project
This project provides a simple web application that allows users to upload images and apply various filters to them. The project is built using Python and Flask, and the image filtering is done using the Pillow library.

## Installation and Usage
To use this project, follow these steps:

Clone the repository:
```ruby
git clone https://github.com/etsond/filter.git
```
Navigate to the project directory:
```bash
cd filter/filterImages
```
Create a virtual environment:
```ruby
python3 -m venv venv
```
Activate the virtual environment:
```ruby
source venv/bin/activate
```
Install the project dependencies:
```ruby
pip install -r requirements.txt
```
Run the Flask application:
```ruby
flask run
```
Open a web browser and go to http://localhost:5000 to use the application.
## Usage
To use the application, simply upload an image file and select the desired filter from the dropdown menu. Click the "Apply Filter" button to apply the filter to the image. The filtered image will be displayed below.

## File Structure
The project files are organized as follows:

- app.py: This is the main Flask application file. It defines the routes and handles the image filtering.
- static/: This directory contains static files such as CSS and JavaScript files.
- templates/: This directory contains the HTML templates for the application.
- uploads/: This directory is where uploaded images are stored.
- requirements.txt: This file lists the Python packages required to run the application.
## Credits
This project was created by Etson Dantas and is licensed under the MIT License. It uses the following open-source libraries:

> Flask

> Pillow
