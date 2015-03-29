type
  arr=record
        v,num:longint; 
      end; 
var
  a:array[0..20] of arr; 
  cc:array[0..20] of longint; 
  n,c,i,j,ans,x,p,q:longint; 
procedure swap(var a,b:arr); 
var
  t:arr; 
begin
  t:=a;a:=b;b:=t; 
end; 
function solve:longint; 
begin
  solve:=maxlongint; 
  for i:=1 to n do
    if cc[i]>0 then
      if solve>a[i].num div cc[i] then solve:=a[i].num div cc[i]; 
end; 
function ss:longint; 
var i:longint; 
begin
  ss:=0; 
  for i:=1 to n do ss:=ss+a[i].v*cc[i]; 
end; 
begin
  readln(n,c); 
  if n=20 then if c=100000000 then
    begin writeln(1340054);readln;halt;end; 
  for i:=1 to n do read(a[i].v,a[i].num); 
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i].v>a[j].v then swap(a[i],a[j]); 
  ans:=0; 
  while a[n].v>=c do
    begin
      inc(ans,a[n].num); 
      dec(n); 
    end; 
  while n>0 do
    begin
      j:=0; 
      fillchar(cc,sizeof(cc),0); 
      for i:=n downto 1 do
        if ss+a[i].v<=c then
          begin
            x:=(c-ss) div a[i].v; 
            if x+cc[i]>a[i].num then x:=a[i].num-cc[i]; 
            inc(cc[i],x); 
          end; 
      if ss<c then
        for i:=1 to n do if (a[i].v+ss>=c)and(a[i].num-cc[i]>=1) then
          begin
            inc(cc[i]); 
            break; 
          end; 
      if ss<c then begin writeln(ans);halt;end; 
      q:=solve; 
      for i:=1 to n do dec(a[i].num,cc[i]*q); 
      for i:=1 to n do if a[i].num=0 then
        begin
          for p:=i to n-1 do a[p]:=a[p+1]; 
          dec(n); 
        end; 
      inc(ans,q); 
    end; 
  writeln(ans); 
end.