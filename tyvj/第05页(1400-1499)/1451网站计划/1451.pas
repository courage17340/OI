type
 rec=record dat,pos:longint; end;
var
 n,m,i,p,x,y,ans:longint;
 tree:array[0..5000000]of record l,r,dat,pos:longint; end;
 v:array[0..1000000]of longint;
 t:rec;
function max(x,y:longint):longint;
 begin
  if x>y then exit(x) else exit(y);
 end;
procedure buildtree(num,l,r:longint);
 var
  mid:longint;
 begin
  tree[num].l:=l; tree[num].r:=r;
  if l=r then begin tree[num].dat:=v[l]; tree[num].pos:=l; exit; end;
  mid:=(l+r)div 2;
  buildtree(num*2,l,mid);
  buildtree(num*2+1,mid+1,r);
  if tree[num*2].dat>tree[num*2+1].dat  then
   begin
    tree[num].pos:=tree[num*2].pos;
    tree[num].dat:=tree[num*2].dat;
   end
  else begin
   tree[num].pos:=tree[num*2+1].pos;
   tree[num].dat:=tree[num*2+1].dat;
  end;
 end;
function ask(num:longint):rec;
 var
  mid,t:longint;
  temp:rec;
 begin
  if (x<=tree[num].l)and(y>=tree[num].r) then
   begin
    ask.pos:=tree[num].pos;
    ask.dat:=tree[num].dat;
    exit;
   end;
  mid:=(tree[num].l+tree[num].r)div 2;
  t:=0;
  if x<=mid then
   begin
    temp:=ask(num*2);
    if t<temp.dat then begin t:=temp.dat; ask.pos:=temp.pos; end;
   end;
  if y>mid then
   begin
    temp:=ask(num*2+1);
    if t<temp.dat then begin t:=temp.dat; ask.pos:=temp.pos; end;
   end;
  ask.dat:=t;
  exit;
 end;
procedure change(num:longint);
 var
  mid:longint;
 begin
  if (tree[num].l=tree[num].r)and(tree[num].l=p) then
   begin
    tree[num].dat:=0;
    exit;
   end;
  mid:=(tree[num].l+tree[num].r)div 2;
  if p<=mid then change(num*2);
  if p>mid then change(num*2+1);
  if tree[num*2].dat>tree[num*2+1].dat then
   begin
    tree[num].pos:=tree[num*2].pos;
    tree[num].dat:=tree[num*2].dat;
   end
  else begin
   tree[num].pos:=tree[num*2+1].pos;
   tree[num].dat:=tree[num*2+1].dat;
  end;
 end;
begin
 read(n,m);
 for i:=1 to n do read(v[i]);
 buildtree(1,1,n);
 ans:=0;
 for i:=1 to m do
  begin
   readln(x,y);
   t:=ask(1);
   ans:=(ans+(t.dat mod 2011)*((x+y)mod 2011))mod 2011;
   p:=t.pos;
   change(1);
  end;
 writeln(ans mod 2011);
end.