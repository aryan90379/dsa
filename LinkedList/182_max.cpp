// app/api/auth/[...nextauth]/route.js
import NextAuth from "next-auth";
import GoogleProvider from "next-auth/providers/google";

const handler = NextAuth({
  providers: [
    GoogleProvider({
      clientId: process.env.GOOGLE_CLIENT_ID,
      clientSecret: process.env.GOOGLE_CLIENT_SECRET,
    }),
  ],
  secret: process.env.NEXTAUTH_SECRET,
  callbacks: {
    async signIn({ user, account }) {
      // your signIn logic here
      return true;
    },
    async jwt({ token, user }) {
      let dbUser = null;
      // your jwt logic here
      return token;
    },
    async session({ session, token }) {
      // your session logic here
      return session;
    },
  },
});

export { handler as GET, handler as POST };
