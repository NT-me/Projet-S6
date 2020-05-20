#ifndef H_QSOMMET
#define H_QSOMMET

#include <QGraphicsItem>
#include <map>
#include <vector>
#include <QPen>
#include <QPainter>
#include "../../../bib/bib.hh"

//Taille du rayon des QSommets en pixel
#define TAILLE_RAYON 10

class QSommet : public QGraphicsItem{

private:
    int id;			/// ID du Sommet &agrave; partie duquel il est construit
    int posx;		/// Position x du Sommet sur la graphicView
    int posy;		/// Position y du Sommet sur la graphicViex
    int rayon;		/// Rayon du Sommet en pixel
    QColor coul;	/// Couleur du Sommet
    bool select;	/// Permet de savoir si le Sommet est s&eacute;l&eacute;ctionn&eacute;

public:
	/**
	 * \brief Constructeur de QSommet
	 * @param Sommet &agrave; partir duquel le QSommet est construit
	 * */
    QSommet(Sommet S);
    
    /**
     * \brief Constructeur par copie de QSommet
     * @param &S Sommet copi&eacute;
     * */
    QSommet(QSommet const &S);
    ~QSommet();		/// Destructeur d'objet QSommet

    int getID() const;		/// Getter de l'ID
    int getPosX() const;	/// Getter de posx
    int getPosY() const;	/// Getter de la posy
    int getRayon() const;	/// Getter de rayon
    QColor getCoul() const;	/// Getter de coul
    bool getSelect() const;	/// Getter de select

    void setID(int id);		/// Setter de l'ID
    void setPosX(int x);	/// Setter de posx
    void setPosY(int y);	/// Setter de posy
    void setRayon(int r);	/// Setter de rayon
    void setCoul(QColor color);		/// Setter de coul
    
    /**
     * \brief Setter de select
     * Modifie l'attribut select du Sommet et sa couleur si s&eacute;l&eacute;ctionn&eacute;e
     * */
    void setSelect(bool select);
    
    /**
     * \brief Double Click
     * Cette m&eacute;thode ouvre une fen&ecirc;tre permettant de modifier l'etiquette ou la charge utile d'un Sommet
     * R&eacute;cupere la paure renvoy&eacute;e par la fen&ecirc;tre de dialogue
     * */
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    /**
     * \brief D&eacute;limitation
     * Cette m&eacute;thode permet de d&eacute;terminer les liites exterieures de la forme qui permettront d'interagie avec elle
     * */

    QRectF boundingRect() const;
    
    /**
     * \brief Dessin de Sommet
     * Cette m&eacute;thode permet de dessiner le Sommet sur ZoneDeDessin
     * Sommet de sa couleur coul ou de la couleur s&eacute;l&eacute;ctionn&eacute;e
     * Sommet avec son etiquette
     * */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif
