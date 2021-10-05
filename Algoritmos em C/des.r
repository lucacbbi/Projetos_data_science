##########ANÁLISE DE COMPONENTES PRINCIPAIS##########
amb=read.csv(file.choose(),h=T,sep=";")
attach(amb) 
ambientais=amb[,2:5] 

ambientais 
install.packages("FactoMineR")
install.packages("factoextra")

desejados
library(FactoMineR)
library(factoextra)
res.pca=PCA(ambientais,graph = F) 
summary(res.pca) 
fviz_eig(res.pca,addlabels = T,ylim=c(0,90)) 
fviz_pca_var(res.pca,col.var = "blue") 
p=fviz_pca_biplot(res.pca,habillage = local,title =NULL,geom = "point"
                  ,pointshape=19,addEllipses=TRUE,ellipse.alpha=0) 

p + scale_color_brewer(palette="Set1")+theme_minimal(12) 

var=get_pca_var(res.pca) 
variaveis=var$cos2 
install.packages("corrplot") 
library(corrplot) 
corrplot(variaveis,is.corr = F) 


