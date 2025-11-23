namespace Terrains
{
    /// @brief Base class for all terrain types.
    class Terrain
    {
        public:
            virtual void setTexture(char newTexture);
        protected:
            char _texture;
        private:

    };
}
