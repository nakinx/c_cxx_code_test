# Specifier parser.

The purpose of this application it's to build a specifier parser.

Usage
-----

Usage: ./parsing_specifier

Example
-------

The function parser_str() build a dynamic string based on format argument
compound by specifiers and each one has a meaning that will be replaced
by a determined value.

parser_str("[%D{%Y-%m-%d %H:%M:%S:%q}][%F][%M][%L]", __FILE__, __PRETTY_FUNCTION__, __LINE__);

The result will be:

[2019-08-28 21:49:22:144][parsing_specifier.cpp][int main(int, char**)][186]

Specifiers
----------

%D{<format>}  The date format is based on strftime().
            %a – Abbreviated weekday name
            %A – Full weekday name
            %b – Abbreviated month name
            %B – Full month name
            %c – Standard date and time string
            %d – Day of month as a decimal(1-31)
            %H – Hour(0-23)
            %I – Hour(1-12)
            %j – Day of year as a decimal(1-366)
            %m – Month as decimal(1-12)
            %M – Minute as decimal(0-59)
            %p – Locale's equivalent of AM or PM
            %q – Milliseconds as decimal(0-999) – Created for logger.
            %S – Second as decimal(0-59)
            %U – Week of year, Sunday being first day(0-53)
            %w – Weekday as a decimal(0-6, Sunday being 0)
            %W – Week of year, Monday being first day(0-53)
            %x – Standard date string
            %X – Standard time string
            %y – Year in decimal without century(0-99)
            %Y – Year including century as decimal
            %Z – Time zone name

%F          File where method was invoked.
%M          Method where method was invoked.
%L          Line where method was invoked.

Most of specifiers are based on the function strftime() and combined with new ones.