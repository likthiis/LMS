#version 1.0
#I just try to complete a simple system to test my skill, do not use it in formal project.

#---------------------------------------------------------------------------------------------------------------------------------
#The functions of this system:
#1. search module
#	Everyone can use this system to search the book it wants.User can input some keywords, like ISBN,title and author, to
#	search the book.Of course, some books may have the same keywords and user can get the result with these books by using
#	this keywords, instead of finding only one book.
#2. register module
#	Beacause this system is built for college,the information of students and teachers will be input uniformly to the system
#	by administrator.Administrators have their rules to register themselves.
#3. borrow module
#	User who is registered can use it to borrow book.
#4. manage module
#	Administrators will have a panel to control this system, they can do the things like users registering, books cataloging and
#	other management objecting.
#5. login module
#	User can use this module to login.By the way, using email is allowed.
#6. recommendation module
#	If user recommends one book to our library, this system will be offered to it to record the information of the book, and 
#	a procedure will start for administrator to audit and catalog.
#7. info diffusion module
#	At all times, this module will release the information to everyone.Information will include the entries like books purchasing
#	and records of violation.
#---------------------------------------------------------------------------------------------------------------------------------