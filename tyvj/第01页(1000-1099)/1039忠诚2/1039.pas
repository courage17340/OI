{ÖÒ³Ï2}
type rec=record L,r,min:longint;end; 
var
  a:array[1..400000] of rec; 
  b:array[1..100000] of longint; 
  n,m,i,j,k,x,y,p:longint; 
procedure make(x:longint); 
var mid,L,r:longint; 
begin
  L:=a[x].L; 
  r:=a[x].r; 
  if L=r then exit; 
  mid:=(L+r) div 2; 
  a[2*x].L:=L;a[2*x].r:=mid;make(2*x); 
  a[2*x+1].L:=mid+1;a[2*x+1].r:=r;make(2*x+1); 
end; 
function min(a,b:longint):longint; 
begin
  min:=a;if a>b then min:=b; 
end; 
procedure work(x:longint); 
var L,r:longint; 
begin
  L:=a[x].L; 
  r:=a[x].r; 
  if L=r then begin a[x].min:=b[L];exit;end; 
  work(2*x);work(2*x+1); 
  a[x].min:=min(a[2*x].min,a[2*x+1].min); 
end; 
function find(x:longint):longint; 
var i,j,k:longint; 
begin
  k:=1; 
  i:=1;j:=n; 
  while i<>j do
    begin
      if x<=(i+j) div 2 then k:=2*k else k:=2*k+1; 
      i:=a[k].L;j:=a[k].r; 
    end; 
  find:=k; 
end; 
function f(x,y,p:longint):longint; 
var i,j,k,mid:longint; 
begin
  i:=a[p].L;j:=a[p].r; 
  if i=j then exit(a[p].min); 
  mid:=(i+j) div 2; 
  if (i=x)and(j=y) then exit(a[p].min); 
  if y<=mid then exit(f(x,y,2*p)); 
  if x>mid then exit(f(x,y,2*p+1)); 
  f:=min(f(x,mid,2*p),f(mid+1,y,2*p+1)); 
end; 
begin
  fillchar(a,sizeof(a),1); 
  read(n,m); 
  a[1].L:=1;a[1].r:=n; 
  make(1); 
  for i:=1 to n do read(b[i]); 
  work(1); 
  for i:=1 to m do
    begin
      readln(p,x,y); 
      if p=1 then write(f(x,y,1),' '); 
      if p=2 then
        begin
          b[x]:=y; 
          j:=find(x);a[j].min:=y; 
          while j>0 do
            begin
              if j mod 2=0
                then a[j div 2].min:=min(a[j].min,a[j+1].min) 
                else a[j div 2].min:=min(a[j].min,a[j-1].min); 
              j:=j div 2; 
              if a[j].min>y then a[j].min:=y; 
            end; 
        end; 
    end; 
end.