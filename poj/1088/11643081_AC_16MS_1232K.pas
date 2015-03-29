const
  dx:array[1..4] of longint=(-1,1,0,0);
  dy:array[1..4] of longint=(0,0,-1,1);
type
  arr=record
        x,y,num:longint;
      end;
var
  n,m,i,j,ans,k,p,q:longint;
  a,b:array[0..101,0..101] of longint;
  s:ansistring;
function max(a,b:longint):longint;
begin
  max:=a;if a<b then max:=b;
end;
function yes(a,b:longint):boolean;
begin
  if a<1 then exit(false);
  if a>n then exit(false);
  if b<1 then exit(false);
  if b>m then exit(false);
  exit(true);
end;
function work(x,y:longint):longint;
var
  i,j:longint;
begin
  if b[x,y]>0 then exit(b[x,y]);
  work:=1;
  for i:=1 to 4 do
    if yes(x+dx[i],y+dy[i]) then
      if a[x,y]>a[x+dx[i],y+dy[i]] then work:=max(work,work(x+dx[i],y+dy[i])+1);
  b[x,y]:=work;
end;
begin
  fillchar(b,sizeof(b),0);
  ans:=0;
  readln(n,m);
  fillchar(a,sizeof(a),0);
  ans:=0;
  for i:=1 to n do
    begin
      readln(s);
      j:=0;
      p:=0;
      for k:=1 to length(s) do
        if s[k] in ['0'..'9'] 
          then p:=p*10+ord(s[k])-48
          else begin inc(j);a[i,j]:=p;p:=0;end;
      inc(j);a[i,j]:=p;
    end;
  for i:=1 to n do for j:=1 to m do b[i,j]:=work(i,j);
  for i:=1 to n do for j:=1 to m do if ans<b[i,j] then ans:=b[i,j];
  writeln(ans);
end.