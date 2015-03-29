const limit=200;
var
  a:array[1..limit] of longint;
  n,i,j,k,p,r,jw,x0,t:longint;
  s,s1:string;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  while not eof do
    begin
      readln(s);
      if pos('.',s)>0 then
        begin
          s1:=copy(s,1,pos(' ',s)-1);
          k:=length(s1)-pos('.',s1);
          if k=6 then k:=0;
          delete(s1,pos('.',s1),1);
          val(s1,x0);
          delete(s,1,pos(' ',s));
          while s[1]=' ' do delete(s,1,1);
        end
        else
          begin
            s1:=copy(s,1,pos(' ',s)-1);
            val(s1,x0);
            k:=0;
            delete(s,1,pos(' ',s));
            while s[1]=' ' do delete(s,1,1);
          end;
      val(s,p);
      fillchar(a,sizeof(a),0);
      r:=limit;
      a[r]:=1;
      for i:=1 to p do
        begin
          for j:=limit downto r do a[j]:=a[j]*x0;
          jw:=0;
          for j:=limit downto r do
            begin
              a[j]:=a[j]+jw;
              jw:=a[j] div 10;
              a[j]:=a[j] mod 10;
            end;
          while jw>0 do
            begin
              dec(r);
              a[r]:=jw mod 10;
              jw:=jw div 10;
            end;
        end;
      k:=k*p;
      t:=limit;
      for i:=r to limit-k do write(a[i]);
      if max(limit-k+1,r)<=t then write('.');
      for i:=1 to k-(limit-r+1) do write(0);
      if max(limit-k+1,r)<=t then
        while a[t]=0 do dec(t);
      for i:=max(limit-k+1,r) to t do write(a[i]);
      writeln;
    end;
end.