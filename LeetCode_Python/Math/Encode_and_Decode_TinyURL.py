'''
Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl 
and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. 
There is no restriction on how your encode/decode algorithm should work. 
You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
'''

'''
Your Codec object will be instantiated and called as such:
Codec codec = new Codec();
codec.decode(codec.encode(url));
'''

class Codec:
	def __init__(self):
		self.map = {}
		self.i = 0

	#Encodes a URL to a shortened URL.
	def encode(self, longUrl):
		self.i += 1
		self.map[self.i] = longUrl
		return 'http://tinyurl.com/' + str(self.i)

	#Decodes a shortened URL to its original URL.
	def decode(self, shortUrl):
		return self.map[int(shortUrl.split('/')[-1])]
		