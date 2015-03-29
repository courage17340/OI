var
  a,b,c:array['A'..'D'] of longint;
  n,i,j,x1,x2,ans,p,k1,k2:longint;
  s:string;
function f(x:longint):char;
begin exit(chr(x+64));end;
begin
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(c,sizeof(c),0);
  readln(s);j:=1;writeln(stderr,s);
  while length(s)>0 do
    begin
      p:=0;
      while s[1] in ['0'..'9'] do
        begin
          p:=p*10+ord(s[1])-48;
          delete(s,1,1);
        end;
      if p=0 then p:=1;
      inc(a[s[1]],p*j);
      delete(s,1,1);
      if s[1]='=' then j:=-1;
      if s[1]=' ' then begin delete(s,1,1);break;end;
      delete(s,1,1);
    end;
  val(s,x1);
  readln(s);j:=1;writeln(stderr,s);
  while length(s)>0 do
    begin
      p:=0;
      while s[1] in ['0'..'9'] do
        begin
          p:=p*10+ord(s[1])-48;
          delete(s,1,1);
        end;
      if p=0 then p:=1;
      inc(b[s[1]],p*j);
      delete(s,1,1);
      if s[1]='=' then j:=-1;
      if s[1]=' ' then begin delete(s,1,1);break;end;
      delete(s,1,1);
    end;
  val(s,x2);
  readln(s);j:=1;writeln(stderr,s);
  while length(s)>0 do
    begin
      p:=0;
      while s[1] in ['0'..'9'] do
        begin
          p:=p*10+ord(s[1])-48;
          delete(s,1,1);
        end;
      if p=0 then p:=1;
      inc(c[s[1]],p*j);
      delete(s,1,1);
      if s[1]='=' then j:=-1;
      delete(s,1,1);
    end;
  for i:=1 to 4 do if a[chr(i+64)]*b[chr(i+64)]<>0 then
    for j:=i+1 to 4 do if a[chr(j+64)]*b[chr(j+64)]<>0 then
      begin
        k1:=(c[f(i)]*b[f(j)]-c[f(j)]*b[f(i)]) div (a[f(i)]*b[f(j)]-a[f(j)]*b[f(i)]);
        k2:=(c[f(i)]*a[f(j)]-c[f(j)]*a[f(i)]) div (b[f(i)]*a[f(j)]-a[f(i)]*b[f(j)]);
        break;
      end;
  if (k1=0)and(k2=0) then
    for i:=1 to 4 do
      begin
        if (a[f(i)]<>0)and(b[f(i)]=0) then k1:=c[f(i)] div a[f(i)];
        if (b[f(i)]<>0)and(a[f(i)]=0) then k2:=c[f(i)] div b[f(i)];
      end;
  ans:=x1*k1+x2*k2;
  if ans>0 then write('+');
  writeln(ans);
  readln;readln;
end.